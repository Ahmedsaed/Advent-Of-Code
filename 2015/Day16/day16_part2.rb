File.open("./input.txt", 'r') do |f|
	target_aunt = {
		"children" => 3,
		"cats" => 7,
		"samoyeds" => 2,
		"pomeranians" => 3,
		"akitas" => 0,
		"vizslas" => 0,
		"goldfish" => 5,
		"trees" => 3,
		"cars" => 2,
		"perfumes" => 1
	}

	best_match = ["", 0]

	f.each_line do |line|
		current_score = 0
		aunt, props = line.split(":", 2)
		
		props.split(",") do |p|
			key = p.split(':')[0].strip
			value = p.split(':')[1].to_i

			if (key == "cats" or key == "trees") and target_aunt[key] < value
				current_score += 1
			elsif (key == "pomeranians" or key == "goldfish") and target_aunt[key] > value
				current_score += 1
			elsif target_aunt[key] == value
				current_score += 1
			end
		end
		
		if current_score > best_match[1]
			best_match[0] = aunt
			best_match[1] = current_score
		end			
	end

	puts "#{best_match[0]} has score of #{best_match[1]}"
end
