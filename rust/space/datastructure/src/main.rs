use std::collections::HashMap;

fn main() {
    // Array, Can't resize and only one type.
    let arry: [i32; 3]= [1,2,3];
    println!("{:?}", arry);
    
    // Vecter, is Array but can resize.
    let mut vect: Vec<i32> = vec![1, 2, 3];
    println!("before {:?}", vect);
    vect.push(4);
    println!("after {:?}", vect);

    // Tuple is Array but can assign more than one type of value.
    let tple = ('O', 1, "two", false);
    println!("{:?}", tple);

    //Hashmap is dictionary in python
    let mut hshmp = HashMap::new();
    hshmp.insert("one", 1);
    hshmp.insert("two", 2);
    hshmp.insert("three", 3);
    hshmp.insert("four", 4);
    
    let mut ordered_hshmp: Vec<_> = hshmp.iter().collect();
    ordered_hshmp.sort_by_key(|&(_, value)| value);
    for (key, value) in ordered_hshmp {
        println!("{} is {}", key, value);
    }
}