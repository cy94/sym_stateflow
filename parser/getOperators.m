function [ ops ] = getOperators(  )
%GETOPERATORS returns cell array of operators 
%   in increasing order of precedence
    ops = {'=', '||', '&&', '~=', '==', '>=', '>', '<=','<', '-', '+', '/', '*'};
end

