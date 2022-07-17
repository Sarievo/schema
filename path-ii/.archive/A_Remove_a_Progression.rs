#![allow(unused_variables)]
#![allow(unused_must_use)]
use std::io::{self, prelude::*};
 
fn solve<R: BufRead, W: Write>(mut input: Scanner<R>, mut w: W) {
    let n: u64 = input.token();
    for _ in 0..n {
        let n: u64 = input.token::<u64>();
        let x: u64 = input.token::<u64>();
        writeln!(w, "{}", (x * 2));
        // writeln!(w, "a:{} b:{}", a, b);
    }
}
 
fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let input = Scanner::from(stdin.lock());
    let writer = io::BufWriter::new(stdout.lock());
    solve(input, writer);
}
 
pub struct Scanner<B> {
    reader: B,
    buffer: Vec<String>,
}
 
impl<R: BufRead> Scanner<R> {
    pub fn token<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
 
impl<R: BufRead> From<R> for Scanner<R> {
    fn from(reader: R) -> Self {
        Self { reader, buffer: Vec::new() }
    }
}