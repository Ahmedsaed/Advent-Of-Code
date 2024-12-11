File.open("./input.txt", 'r') do |f|
	safe_count = 0

	f.each_line do |line|
		levels = line.split(" ").map!(&:to_i)

		is_sorted = levels.each_cons(2).all? { |p, n| (p <=> n) != 1 } || 
					levels.each_cons(2).all? { |p, n| (p <=> n) != -1 }

		next if !is_sorted

		is_safe = levels.each_cons(2).all? { |p, n| 1 <= (p - n).abs && (p - n).abs <= 3}
		  
		next if !is_safe
		
		safe_count += 1
	end

	puts "Safe Count: #{safe_count}"
end
