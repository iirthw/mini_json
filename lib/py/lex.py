w = "{ name: GSP, age : 39 }"
seq = ['{', ' ', 'name', ':', 'GSP', ',', 'age', ':', '39', '}']

def lex(s):
	print('Parsing ' + s)
	print(len(s))
	while len(s):
		s = s[1:]
		print(len(s))

def main():
	lex(w)

if __name__ == "__main__":
	main()
