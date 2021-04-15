s = ['{', 'name', ':', 'GSP', ',', 'age', ':', '39', 'isChamp', ':', 'true', '}']

LEFT_BRACE = '{'
RIGHT_BRACE = '}'
LEFT_BRACKET = '['
RIGHT_BRACKET = ']'

# recursively parse tokens
# each of the subroutines parse_array and parse_object will recursively call
# parse (unless simple cases when further recursion might not be required)
def parse(tokens):
    t = tokens[0]
    if t == LEFT_BRACKET:
        return parse_array(tokens[1:])
    elif t == LEFT_BRACE:
        return parse_object(tokens[1:])
    else:
        return t, tokens[1:]

# ==============================================================================
#
# ==============================================================================
def parse_object(tokens):
    pass

# ==============================================================================
#
# ==============================================================================
def parse_array(tokens):
    json_array = []
    t0 = t[0]
    if t0 == RIGHT_BRACKET:
        return json_array, tokens[1:]

    while True:
        json, tokens = parse(tokens)
        json_array.append(json)
        
        if !len(tokens):
            raise Exception('No closing bracket found')

        t = tokens[0]
        if t == RIGHT_BRACKET:
            return json_array, tokens[1:]
        elif t != COMMA:
            raise Exception('Expected a comma after object in the array')
        else:
            tokens = tokens[1:]


# ==============================================================================
#
# ==============================================================================
def main():
    print("ololol")

if __name__ == "__main__":
    main()