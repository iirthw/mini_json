w = "{ name: GSP, age : 39 }"
seq = ['{', ' ', 'name', ':', 'GSP', ',', 'age', ':', '39', '}']

def lex(s):
    tokens = []
	while len(s):
        token, s = lex_brace(s)
		if token != None
            tokens.append(token)
            continue

        token, s = lex_bracket(s)
		print(len(s))

def lex_brace(s):
    pass

def lex_bracket(s):
    pass

def lex_string(s):
    pass

def lex_number(s):
    pass

def lex_bool(s):
    pass

def main():
	lex(w)

if __name__ == "__main__":
	main()
