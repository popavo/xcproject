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

SUB_RPATHS = ["Frameworks", "OtherFrameworks", "SharedFrameworks", "Plugins"]

$rpaths = []

def has_rpath(rpath)
  has_xcode_in_rpath = false

  $rpaths.each do |path|
    next unless path == rpath
    has_xcode_in_rpath = true
    break
  end
  
  has_xcode_in_rpath
end

def add_rpaths(base=XCODE_CONTENTS_PATH)
  SUB_RPATHS.each do |subpath|
    next if has_rpath(XCODE_CONTENTS_PATH + subpath)
    next if has_rpath(File.join(XCODE_DEV_PATH.to_s, "..", subpath))
    next if has_rpath(base + subpath)
    rpath = base + subpath
    `install_name_tool -add_rpath #{rpath} \"#{XCPROJECT_PATH}\"`
  end
end

def find_rpaths()
  load_commands = `otool -l \"#{XCPROJECT_PATH}\"`

  load_commands.gsub(/cmd LC_RPATH\n.+?\n\s+path\s+([^ ]+) \(.+?\)/) do |m|
    $rpaths << $1
    "#{m}"
  end
end

find_rpaths
add_rpaths

exec(XCPROJECT_PATH, *ARGV)