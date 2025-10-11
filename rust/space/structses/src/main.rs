#[derive(Default)]
struct Person {name: String, age: i32, active: bool}
impl Person {
    fn display(&self) {
        println!("name {}, {} years old, status: {}", self.name, self.age, self.active)
    }
    fn update(&mut self, name:&str, age:i32, active:bool){
        self.name = name.to_string();
        self.age = age;
        self.active = active;
    }
}

fn main(){
    let mut maisa = Person::default();
    maisa.update("Kuranne Maisa", 18, true);
    maisa.display();
}