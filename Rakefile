require 'rake/clean'

### general definitions

TARGET  = 'uctest'

CFLAGS  = '--std=c99 -W -Wall -Iinclude'
LDFLAGS = ''

SRCS    = FileList['src/**/*.c']
OBJS    = SRCS.ext('o')

CLEAN.include(OBJS)
CLOBBER.include(TARGET)

### tasks

task :default => [ :build, :run ]

task :build => [ TARGET ]

task :run => [ TARGET ] do
  sh "echo ; ./#{TARGET}"
end

### rules

rule '.o' => '.c' do |t|
  sh "cc -c #{CFLAGS} -o #{t.name} #{t.source}"
end

file TARGET => OBJS do
  sh "cc #{CFLAGS} #{LDFLAGS} -o #{TARGET} #{OBJS}"
end
