#!/usr/bin/env ruby

begin
    BASE_DIR = File.expand_path(File.dirname(File.readlink(__FILE__))) # this may be a symlink, resolve to real location
rescue
    BASE_DIR = File.expand_path(File.dirname(__FILE__)) # for local debugging
end

require 'pathname'

XCPROJECT_PATH = File.join(BASE_DIR, "_xcproject")
XCODE_DEV_PATH = Pathname.new(`xcode-select -p`.strip)
XCODE_CONTENTS_PATH = XCODE_DEV_PATH.dirname
XCODE_PATH = XCODE_CONTENTS_PATH.dirname
SUB_RPATHS = ["Frameworks", "OtherFrameworks", "SharedFrameworks"]

def has_rpath(rpath, rpaths)
  rpaths.each do |path|
    next unless path == rpath
    return true
  end
end

def add_rpaths(base, rpaths)
  SUB_RPATHS.each do |subpath|
    next if has_rpath(XCODE_CONTENTS_PATH + subpath, rpaths)
    next if has_rpath(XCODE_DEV_PATH.dirname + subpath, rpaths)
    next if has_rpath(base + subpath, rpaths)
    rpath = base + subpath
    `install_name_tool -add_rpath #{rpath} \"#{XCPROJECT_PATH}\"`
  end
end

def find_rpaths
  paths = []
  load_commands = `otool -l \"#{XCPROJECT_PATH}\"`
  load_commands.scan(/cmd LC_RPATH\n.+?\n\s+path\s+([^ ]+) \(.+?\)/) do |path|
    paths << path
  end
  paths
end

# catch any exceptions thrown by this procedure and just execute _xcproject as is
begin
  if XCODE_DEV_PATH.exist? or ENV["xcode"]
    rpaths = find_rpaths
    xcode_path = ENV["xcode"] || XCODE_CONTENTS_PATH
    add_rpaths(xcode_path, rpaths)
  else
    puts "Unable to locate Xcode, RPATH checking requires it. Use 'xcode-select -s path/to/Xcode.app' to fix this"
  end
end

exec(XCPROJECT_PATH, *ARGV)