require 'ruby2d'

$COLORS = [
  Color.new([1, 0, 0, 1]),
  Color.new([1, 0.25, 0, 1]),
  Color.new([1, 0.5, 0, 1]),
  Color.new([1, 0.75, 0, 1]),
  Color.new([1, 1, 0, 1]),
  Color.new([0.75, 1, 0, 1]),
  Color.new([0.5, 1, 0, 1]),
  Color.new([0.25, 1, 0, 1]),
  Color.new([0, 1, 0, 1]),
  Color.new([0, 1, 0.25, 1]),
  Color.new([0, 1, 0.5, 1]),
  Color.new([0, 1, 0.75, 1]),
  Color.new([0, 1, 1, 1]),
  Color.new([0, 0.75, 1, 1]),
  Color.new([0, 0.5, 1, 1]),
  Color.new([0, 0.25, 1, 1]),
  Color.new([0, 0, 1, 1]),
  Color.new([0.25, 0, 1, 1]),
  Color.new([0.5, 0, 1, 1]),
  Color.new([0.75, 0, 1, 1]),
  Color.new([1, 0, 1, 1]),
  Color.new([1, 0, 0.75, 1]),
  Color.new([1, 0, 0.5, 1]),
  Color.new([1, 0, 0.25, 1])
]

$blocks = Hash.new

def draw_block(block, color, base)
  block = (block.split[1, 2]) .map { |n| n.to_i }
  return if block[1] < base
  block[1] -= base
  r = Rectangle.new(
    color: color,
    x: (block[1] % 1024),
    y: (block[1] / 1024) * 20 + (block[1] / 1024) * 2,
    width: block[0],
    height: 20
  )
  r = [r]
  if r[0].width + r[0].x > 1024
    w = r[0].width
    r[0].width = (1024 - r[0].x)
    w = w - r[0].width
    r << Rectangle.new(
      color: r[0].color,
      x: 0,
      y: r[0].y + 22,
      width: w,
      height: 20
    )
  end
  r << Text.new(
    "#{block[0]}",
    x: r[0].x + 4,
    y: r[0].y + 4,
    font: "/usr/share/fonts/TTF/FiraCode-Bold.ttf",
    size: 10,
    color: "white",
    z: 10
  )
  $blocks[block[1]] = r
end

def free_block(block, base)
  elem = $blocks[((block.split)[2]).to_i - base]
  return if elem.nil?
  (elem.class.name == "Array") ? elem.each { |n| n.remove } : elem.remove
end
