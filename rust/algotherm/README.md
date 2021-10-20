# rustで書いてみる

章ごとにファイルを分ける。
実行は`cargo test`で確認する


## exec
```shell
# 標準入力を受け付ける処理も書くので起動するテストは指定する
$ cargo test ex1

# println!を確認する場合
$ cargo test ex1 -- --nocapture
```
