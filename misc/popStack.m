function [ element, stk ] = popStack( stack )
%POPSTACK Pop an element from stack and return it
%   stack: a cell array representing a stack
%   where the first element is the top of the stack
%   popStack returns the first element and 
%   a new cell array with the first element removed
% 
%   If the stack is empty, both element and stk are empty
    
    if(length(stack) == 1)    
        element = stack{1};
        stk = {};
    elseif(isempty(stack))
        element = [];
        stk = {};
    else
        element = stack{end};
        stk = stack(1:end-1);
    end
end

