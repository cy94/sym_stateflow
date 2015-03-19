s{1} = 'x = x + 2';

for i = 1 : length(s)
    string = char(s(i));
    fprintf('\n---------\nInput:\n%s', string);
    parse(string)
    fprintf('\nOutput:\n');    
    fprintf('\n---------\n')
end
