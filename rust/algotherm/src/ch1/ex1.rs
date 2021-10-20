fn ex1 () {
    println!("Hello, World!")
}

#[cfg(test)]
mod tests {
    use super::ex1;
    #[test]
    fn test_ex1() {
        ex1()
    }
}
