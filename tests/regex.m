% regular expression(s) for Stateflow State labels (state name + actions)
% matches with 
%     (state name)(newline)
%     en: (multi line actions)    
%         ...        (newline) 
%     du: (multi line actions)    
%         ...        (newline)
%     ex: (multi line actions)    
%         ...        
            
expr = '(?<name>.*)?\nen:(?<entry>.*)\ndu:(?<during>.*)\nex:(?<exit>.*)';

% test strings
% simple - all actions
s{1} = sprintf('A\nen: x = x + 2;\ndu: x = x  + 3;\nex: x = x + 4;');
% multiple lines in an action
s{2} = sprintf('A\nen: x = x + 2;\ny = y + 2;\ndu: x = x + 3;\nex: x = x + 4;\n');
% state name with 2 words
s{3} = sprintf('ABC DEF\nen: x = x + 2;\ndu: x = x  + 3;\nex:');
% missing action(s)
s{4} = sprintf('ABC\nen: x = x + 2;\ndu: x = x  + 3;\nex:');
s{5} = sprintf('ABC\nen:\ndu: x = x  + 3;\nex:');
s{6} = sprintf('ABC\nen:\ndu:\nex: x = x + 4;');
s{7} = sprintf('ABC\nen:\ndu:\nex:');

% test
for i = 1 : length(s)
    string = char(s(i));
    fprintf('\n---------\nInput:\n%s', string);
    out = regexp(string, expr, 'names');
    fprintf('\nOutput:\n');
    disp(out);
    fprintf('\n---------\n')
end


