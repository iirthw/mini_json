w = '{\"name\": \"GSP\", \"age\" : 39,  "isChamp": true }'
seq = ['{', ' ', 'name', ':', 'GSP', ',', 'age', ':', '39', '}']

LEX_BRACE = ['{', '}']
LEX_BRACKET = ['[', ']']
LEX_SEPARATOR = [',', ':']
LEX_NUMBER = '0123456789'
LEX_DOUBLE_QUOTE = '\"'
LEX_WHITE_SPACE = [' ', '\t', '\n']
LEX_TRUE = 'true'
LEX_FALSE = 'false'

def lex(s):
    tokens = []
    while len(s):
        # brace
        token, s = lex_brace(s)
        if token is not None:
            tokens.append(token)

        # bracket
        token, s = lex_bracket(s)
        if token is not None:
            tokens.append(token)

        # separator
        token, s = lex_separator(s)
        if token is not None:
            tokens.append(token)

        # string
        token, s = lex_string(s)
        if token is not None:
            tokens.append(token)

        # number
        token, s = lex_number(s)
        if token is not None:
            tokens.append(token)

        # bool
        token, s = lex_bool(s)
        if token is not None:
            tokens.append(token)

        # whitespace
        token, s = lex_whitespace(s)

    return tokens

def lex_brace(s):
    if not s:
        return None, s
    elif s[0] in LEX_BRACE:
        return s[0], s[1:]
    else:
        return None, s

def lex_bracket(s):
    if not s:
        return None, s
    elif s[0] in LEX_BRACKET:
        return s[0], s[1:]
    else:
        return None, s

def lex_string(s):
    if not s:
        return None, s
    elif s[0] == LEX_DOUBLE_QUOTE:
        i = 1
        while (i < len(s)): 
            if (s[i] == LEX_DOUBLE_QUOTE):
                return s[1:i], s[i+1:]
            else:
                i += 1

    return None, s

def lex_whitespace(s):
    if not s:
        return None, s
    elif s[0] in LEX_WHITE_SPACE:
        return None, s[1:]
    else:
        return None, s

def lex_separator(s):
    if not s:
        return None, s
    elif s[0] in LEX_SEPARATOR:
        return s[0], s[1:]
    else:
        return None, s

def lex_number(s):
    i = 0
    while i < len(s) and (s[i] in LEX_NUMBER):
        i += 1

    if not i:
        return None, s
    else:
        return s[:i], s[i+1:]

def lex_bool(s):
    if len(s) >= 4 and s[:4] == LEX_TRUE:        
        return LEX_TRUE, s[4:]
    elif len(s) >= 5 and s[:5] == LEX_FALSE:
        return LEX_FALSE, s[5:]
    else:        
        return None, s

def main():
    tokens = lex(w)
    print(tokens)

if __name__ == "__main__":
    main()
