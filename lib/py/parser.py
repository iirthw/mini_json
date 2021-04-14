s = ['{', 'name', ':', 'GSP', ',', 'age', ':', '39', 'isChamp', ':', 'true', '}']

LEFT_BRACE = '{'
LEFT_BRACKET = '['

def parse(tokens):
    t = tokens[0]
    if t == LEFT_BRACKET:
        return parse_array(tokens[1:])
    elif t == LEFT_BRACE:
        return parse_object(tokens[1:])
    else:
        return t, tokens[1:]

def parse_object(s):
    pass

def parse_array(s):
    pass

def main():
    print("ololol")

if __name__ == "__main__":
    main()