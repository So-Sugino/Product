# 注意
zdd-const、seqbdd-constはSAPPOROBDDライブラリを用いてZDD、SeqBDDを構築します。SAPPOROBDD内のapp下に中身のフォルダを配置して活用してください。

# 各app説明
## zdd-const
各行にアイテムの組合せが書かれたファイルを入力とし、それを表現するZDDを構築します。
現状、アイテム番号は1以上の数値で設定されていることと各組合せがソートされている入力にのみ正常に動作します（いずれ修正します）。

### zdd-const/naive
素朴な手法による構築をします。

### zdd-const/recursive
再帰的な構築をします。
組合せ集合がソートされている場合のみ正常に動作します。

## seqbdd-const
各行に文字列が書かれたファイルを入力とし、それを表現するSeqBDDを構築します。

### seqbdd-const/naive
素朴な手法による構築をします。

### seqbdd-const/reverse
最も高速に素朴な手法で構築します。
文字列集合がソートされている場合のみ正常に動作します。

### seqbdd-const/recursive
再帰的な構築をします。
文字列集合がソートされている場合のみ正常に動作します。