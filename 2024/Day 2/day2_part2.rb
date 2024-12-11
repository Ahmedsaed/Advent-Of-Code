def is_safe(levels)
	is_sorted = levels.each_cons(2).all? { |p, n| (p <=> n) != 1 } || 
							levels.each_cons(2).all? { |p, n| (p <=> n) != -1 }

	return false if !is_sorted

	is_safe = levels.each_cons(2).all? { |p, n| 1 <= (p - n).abs && (p - n).abs <= 3}

	return false if !is_safe

	return true
end

File.open("./input.txt", 'r') do |f|
	safe_count = 0

	f.each_line do |line|
		levels = line.split(" ").map!(&:to_i)

		if is_safe(levels)
			safe_count += 1
			next
		end
		
		for i in 0..levels.length - 1
			new_levels = levels.dup
			new_levels.delete_at(i)

			if is_safe(new_levels)
				safe_count += 1
				break
			end
		end
	end

	puts "Safe Count: #{safe_count}"
end
