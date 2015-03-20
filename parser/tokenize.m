function [ tokens ] = tokenize( in_string )
%TOKENIZE Summary of this function goes here
%   Detailed explanation goes here
%     split on whitespace
%     fix to do proper lexical analysis later
    tokens = strsplit(in_string);
%     remove empty tokens
    tokens(strcmp('', tokens)) = [];
end

