function [ ops ] = getOperators(  )
%GETOPERATORS returns cell array of operators 
%   Operators are in increasing order of precedence
    ops = {'=', '||', '&&', '~=', '==', '>=', '>', '<=','<', '-', '+', '/', '*'};
end

