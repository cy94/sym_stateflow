function [ AST ] = parse( in_string )
%PARSE parses code given as string and creates AST
%   creates Abstract Syntax Tree (AST.m) by parsing
%   code in Stateflow en / du / ex actions and 
%   transition guard / action
%   assumes that code syntax is correct
    fprintf('Parsing: %s\n', in_string);
    
    operators = getOperators();
    
%     operator stack - contains operator strings ('+', '-' ...)
    opr_stk = {};
%     operand stack - contains ASTNodes
    opn_stk = {};
%   cell array of tokens in code
    tokens = tokenize( in_string );
    
    fprintf('Tokens: ');
    disp(tokens);
    
    for i = 1 : length(tokens)
%         check if operator
        prec = precedence( tokens{i} );
%       not an operator - variable or constant
        if(isempty(prec))
            fprintf('Token: %s\n', tokens{i});
            opn_stk{end + 1} = tokens{i};
%       found operator    
        else 
            fprintf('Token: %s Prec: %d\n', tokens{i}, prec);
%           check for higher precedence operators in stack
            if(~isempty(opr_stk))
                while(precedence(opr_stk{end}) >= prec)
    %                     pop 2 operands off stack
                        [opn1, opn_stk] = popStack(opn_stk);
                        [opn2, opn_stk] = popStack(opn_stk);
    %                     pop operator off stack
                        [opr, opr_stk]  = popStack(opr_stk);
    %                     add new node to opn_stk
                        opn_stk{end + 1} = newASTNode(opr, opn1, opn2);
                end 
            end
%             add this operator to opr_stk
            opr_stk{end + 1} = tokens{i};
        end
    end
end

