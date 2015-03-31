function [ lines ] = getLines( in_string )
%GETLINES splits a string of code on semicolons
%   splits a string of code on semicolons, strips whitespace
%   and returns a cell array of lines
%     eg: x = x + 1; <whitespace> y = y + 1;
%     ->
%     { 'x = x + 1', 'y = y + 1' }
    
%   split on ';'
    lines = strtrim(strsplit(in_string, ';'));
%   remove empty lines
    lines(strcmp('', lines)) = [];
end

