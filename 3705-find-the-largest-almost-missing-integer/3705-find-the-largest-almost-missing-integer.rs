impl Solution {
    fn max_element(nums : &Vec<i32>) -> i32{
        let mut ans : i32 = 0;
        for i in 0..nums.len(){
            if nums[i] > ans { ans = nums[i] };
        }
        return ans;
    }

    pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        let n : usize = nums.len();
        let mut freq = std::collections::HashMap::new();
        let k = k as usize;

        for &i in &nums{
            *freq.entry(i).or_insert(0) += 1;
        }

        if k == n  { return Self::max_element(&nums);}
        else if k == 1 {
            let mut ans : i32 = -1;
            for (&key, &val) in freq.iter(){
                if val == 1 && key > ans {
                    ans = key;
                }
            }
            return ans;
        }


        if freq[&nums[0]] == 1 && freq[&nums[n-1]] == 1 {
            return std::cmp::max(nums[0], nums[n - 1]);
        }
        else if freq[&nums[0]] == 1 && freq[&nums[n - 1]] > 1 {
            return nums[0];
        }
        else if freq[&nums[n - 1]] == 1 && freq[&nums[0]] > 1 {
            return nums[n - 1];
        }
        else if &nums[0] == &nums[n - 1] {
            return -1;
        }

        return -1;
    }
}