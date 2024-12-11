string = File.open("./input.txt", 'r').read
regex = /mul\((\d{1,3}),(\d{1,3})\)/

matches = string.scan(regex)

total = 0

matches.each do |num1, num2|
  total += num1.to_i * num2.to_i
end

puts "Part 1: #{total}"

# Part 2
regex = /(don't\(\)|do\(\)|mul\((\d{1,3}),(\d{1,3})\))/

total = 0
capture = true

matches = string.scan(regex)
matches.each do |full_match, num1, num2|
  if full_match == "do()"
    capture = true
  elsif full_match == "don't()"
    capture = false
  elsif capture
    total += num1.to_i * num2.to_i if capture
  end
end

puts "Part 2: #{total}"
