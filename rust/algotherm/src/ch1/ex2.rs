fn ex2() {
    println!("Enter a char: ");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Failed.");
    println!("You entered: {}", input);
}

#[cfg(test)]
mod tests {
    use super::ex2;
    #[test]
    fn test_ex2() {
        ex2()
    }
}
