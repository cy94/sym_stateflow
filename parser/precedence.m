function [ prec ] = precedence( operator )
%PRECEDENCE finds the precedence of operator in cell array of operators
%   operators are returned by getOperators
    operators = getOperators();
    prec = find(strcmp(operators, operator));
end

