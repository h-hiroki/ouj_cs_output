fn ex6() {
    let celsius = 36.5;
    let fahrenheit = (9.0 / 5.0) * celsius + 32.0;
    println!("{} (celsius) = {} (fahrenheit)", celsius, fahrenheit)
}

#[cfg(test)]
mod tests {
    use super::ex6;
    #[test]
    fn test_ex6() {
        ex6()
    }
}
