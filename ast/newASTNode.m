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
                node = Product(opn1, opn2);
            case '/'
                node = Quotient(opn1, opn2);
            case '+'    
                node = Sum(opn1, opn2);
            case '-'    
                node = Difference(opn1, opn2);
            case '='    
                node = Assignment(opn1, opn2);
        end
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

