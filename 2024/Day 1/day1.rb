File.open("./input.txt", 'r') do |f|
	l1, l2 = [], []

	f.each_line do |line|
		item1, item2 = line.split("   ")
		l1.push(item1.to_i)
		l2.push(item2.to_i)
	end

	l1.sort!
	l2.sort!

	distance = 0

	for i in 0..l1.length - 1
		distance += (l1[i] - l2[i]).abs
	end

	puts "Part 1: The distance is #{distance}"

	l2_freq = l2.tally
	score = 0

	for i in 0..l1.length - 1
		score += l1[i] * l2_freq.fetch(l1[i], 0)
	end

	puts "Part 2: The score is #{score}"
end
