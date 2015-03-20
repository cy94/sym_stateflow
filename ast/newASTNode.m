function [ node ] = newASTNode( varargin )
%NEWASTNODE creates an AST node based on args
%   one arg - constant or variable
%   eg: 1, 2, 'x', 3.5

%   3 args - operator, ast1, ast2
%   forms a new node operator(ast1, ast2)
%   eg: '+', ast1, ast2 ->     
%       +
%      / \ 
%     /   \
%   ast1  ast2

%   binary operator
%       arg1: operator
%       arg2: left child
%       arg3: right child

    if(nargin == 3)
        opr = varargin{1};
        opn1 = varargin{2};
        opn2 = varargin{3};
        
        switch opr
            case '*'
                f = @Product;
            case '/'
                f = @Quotient;
            case '+'    
                f = @Sum;
            case '-'    
                f = @Difference;
            case '<'
                f = @LessThan;
            case '<='
                f = @LessThanEqual;               
            case '>'
                f = @GreaterThan; 
            case '>='
                f = @GreaterThanEqual;
            case '=='
                f = @Equals;
            case '~='
                f = @NotEquals;
            case '&&'
                f = @And;
            case '||'
                f = @Or;                
            case '='    
                f = @Assignment;
        end
        node = f(opn1, opn2);
%   constant or variable        
    elseif(nargin == 1) 
        value = str2num(varargin{1});
        
%       not a number - variable
        if(isempty(value))
            node = Variable(varargin{1});
        else % number
            node = Constant(value);
        end    
    end
end

