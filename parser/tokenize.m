function [ tokens ] = tokenize( in_string )
%TOKENIZE tokenize a MATLAB code statement
%     splits given code string into tokens
%     by splitting on whitespace
    tokens = strsplit(in_string);
%     remove empty tokens
    tokens(strcmp('', tokens)) = [];
end

