use std::{fs};
use std::collections::{HashSet};
#[derive(Debug, Clone)]
#[derive(Eq, Hash, PartialEq)]
struct Point {
    x: i32,
    y: i32
}

struct Rope {
    knots: Vec<Point>,
    visited: HashSet<(i32, i32)>,
    n: usize
}

impl Rope {
    fn new(n: usize) -> Rope {
        Rope { knots: vec![Point{x: 0, y:0}; n], visited: HashSet::new(), n }
    }

    fn move_rope(&mut self, cmd: &str) {
        match cmd {
            "D" => self.knots[0].y -= 1,
            "U" => self.knots[0].y += 1,
            "R" => self.knots[0].x += 1,
            "L" => self.knots[0].x -= 1,
            _ => { println!("Invalid Direction"); }
        }; 

        for i in 1..self.n {
            Rope::update_knots(self, i as usize);
        }
        
        self.visited.insert((self.knots[self.n-1].x, self.knots[self.n-1].y));
    }

    fn update_knots(&mut self, leader_index: usize) {
        let leader_position = &self.knots[leader_index-1];
        let follower_position = &self.knots[leader_index];

        let row_diff = leader_position.x - follower_position.x;
        let col_diff = leader_position.y - follower_position.y;
    
        let mut follower_position = &mut self.knots[leader_index];

        if row_diff == 0 && col_diff > 1 {
            follower_position.y += col_diff.signum();
        } else if col_diff == 0 && row_diff > 1 {
            follower_position.x += row_diff.signum();
        } else if col_diff.abs() > 1 || row_diff.abs() > 1 {
            follower_position.y += col_diff.signum();
            follower_position.x += row_diff.signum();
        }
    }
}

fn main() {
    let file = fs::read_to_string("/home/ahmed/Documents/Projects/Problem Solving/Advent-Of-Code/2022/Day_9/input.txt").expect("No File Found");
    
    let mut part1 = Rope::new(2);
    let mut part2 = Rope::new(10);

    for line in file.split("\n") {
        let (cmd, n) = line.split_once(" ").unwrap();
        let n = n.parse().expect("Expected Integer"); 

        for _ in 0..n {
            part1.move_rope(&cmd);
            part2.move_rope(&cmd);
        }
    }

    println!("{}", part1.visited.len());
    println!("{}", part2.visited.len());
}
