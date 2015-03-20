classdef Assignment < Operator
    %ASSIGNMENT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Assignment(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

