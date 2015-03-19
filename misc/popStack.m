function [ element, stk ] = popStack( stack )
%POPSTACK Summary of this function goes here
%   Detailed explanation goes here
    
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

