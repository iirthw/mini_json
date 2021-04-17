s = ['{', 'name', ':', 'GSP', ',', 'age', ':', '39', 'isChamp', ':', 'true', '}']

LEFT_BRACE = '{'
RIGHT_BRACE = '}'
LEFT_BRACKET = '['
RIGHT_BRACKET = ']'
COLON = ':'

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
    json_obj = {}
    t0 = tokens[0]
    if t0 == RIGHT_BRACE:
        return json_obj, tokens[1:]

    while True:
        key, tokens = parse(tokens)

        if len(tokens) != 0:
            raise Exception('No closing right brace found')

        t = tokens[0]
        if t == RIGHT_BRACE:
            return json_obj, tokens[1:]
        elif t != COLON:
            raise Exception('Colon : expected between key-value pairs')
        else:
            value, tokens_rest = parse(tokens[1:])
            json_obj[key] = value
            tokens = tokens_rest


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
        
        if len(tokens) != 0:
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