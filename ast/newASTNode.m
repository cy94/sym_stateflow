function [ node ] = newASTNode( varargin )
%NEWASTNODE Summary of this function goes here
%   Detailed explanation goes here

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
    elseif(nargin == 1) %     constant or variable
        value = str2num(varargin{1});
        
%       not a number - variable
        if(isempty(value))
            node = Variable(varargin{1});
        else % number
            node = Constant(value);
        end    
    end
end

