#!/bin/bash

cleanup() {
	rm -f cmp out
}

assert() {
  # テストしようとしている内容をprint
	printf '%-30s:' "\"$1\" \"$2\"\"$3\" \"$4\""

	# bashの出力をcmpに保存
	echo -n -e "$1" "$2" | bash >cmp 2>&-
	# bashのexit statusをexpectedに代入
	expected=$?
	# minishellの出力をoutに保存
	echo -n -e "$1" "$2" | ./minishell >out 2>&-
	# minishellのexit statusをactualに代入
	actual=$?

	# bashとminishellの出力を比較
	diff cmp out >/dev/null && echo -n '  diff OK' || echo -n '  diff NG'

	# bashとminishellのexit statusを比較
	if [ "$actual" = "$expected" ]; then
		echo -n '  status OK'
	else
		echo -n "  status NG, expected $expected but got $actual"
	fi
	echo
}

# Empty line (EOF)
assert 'ls -l' '|' 'wc -l'
assert 'ls -l' 'srcs/main.c'
assert 'echo' 'mahayase'
assert 'echo -n' 'mahayase'

cleanup
echo 'all OK'