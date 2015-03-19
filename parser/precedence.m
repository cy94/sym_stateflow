function [ prec ] = precedence( operator )
%PRECEDENCE finds the precedence of operator in cell array of operators
%   Detailed explanation goes here
    operators = getOperators();
    prec = find(strcmp(operators, operator));
end

