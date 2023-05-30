require 'ruby2d'
require_relative 'lib/lib2d.rb'

f = File.open("log.txt", "r")
fd = f.readlines.map &:chomp

set width: 1024, height: 768, title: "MemMap"

on :key do |event|
  if event.key == "escape"
    exit
  end
end

base = fd[1].split[2].to_i
y_offset = 0
tick = 0
counter = 0

update do
  next if counter == fd.length
  if tick % 5 == 0
    if fd[counter][0] == 'A'
      draw_block fd[counter], $COLORS[counter % $COLORS.length], base
    else
      free_block fd[counter], base
    end
    counter += 1
  end
  tick += 1

end

show
