w = '{ \"name\": \"GSP\", \"age\" : 39 }'
seq = ['{', ' ', 'name', ':', 'GSP', ',', 'age', ':', '39', '}']

JSON_BRACE = ['{', '}']
JSON_BRACKET = ['[', ']']
JSON_SEPARATOR = [',', ':']
JSON_NUMBER = range(0, 9)
DOUBLE_QUOTE = '\"'
WHITE_SPACE = [' ', '\t', '\n']

def lex(s):
    tokens = []
    while len(s):
        # braces
        token, s = lex_brace(s)
        if token is not None:
            tokens.append(token)
            continue

        # brackets
        token, s = lex_bracket(s)
        if token is not None:
            tokens.append(token)
            continue

        # separators
        token, s = lex_separator(s)
        if token is not None:
            tokens.append(token)
            continue

        # strings
        token, s = lex_string(s)
        if token is not None:
            tokens.append(token)
            continue

        # numbers
        token, s = lex_number(s)
        if token is not None:
            tokens.append(token)
            continue

        # whitespace
        token, s = lex_whitespace(s)

        print(s)

def lex_brace(s):
    if s[0] in JSON_BRACE:
        return s[0], s[1:]
    else:
        return None, s

def lex_bracket(s):
    if s[0] in JSON_BRACKET:
        return s[0], s[1:]
    else:
        return None, s

def lex_string(s):
    if s[0] == DOUBLE_QUOTE:
        i = 1
        while (i < len(s)): 
            if (s[i] == DOUBLE_QUOTE):
                print(s[i])
                return s[1:i], s[i+1:]
            else:
                i += 1

    return None, s

def lex_whitespace(s):
    if s[0] in WHITE_SPACE:
        return None, s[1:]
    else:
        return None, s

def lex_separator(s):
    if s[0] in JSON_SEPARATOR:
        return s[0], s[1:]
    else:
        return None, s

def lex_number(s):
    i = 0
    while (i < len(s) and s[i] in JSON_NUMBER):
        i += 1

    return s[:i], s[i+1:]

def lex_bool(s):
    pass

def main():
    lex(w)

if __name__ == "__main__":
    main()
