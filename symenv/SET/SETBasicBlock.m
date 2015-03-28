classdef SETBasicBlock
    %SETBASICBLOCK Variable -> AST Mappings in the SET
    %   SET = Symbolic Execution Trace
     
    %   Used to store mappings of variables to current values
    %   during symbolic execution
    %   Uses a containers.Map object with
    %         key = Variable Name (string)
    %   and   value = AST node (ASTNode) value for that variable
    
    properties
        map
    end
    
    methods
        function obj = SETBasicBlock()
            obj.map = containers.Map();
        end
         
%         variable: name of the variable (string)
%         AST: AST expression for value of variable
        function set(obj, varname, AST)
            obj.map(varname) = AST;
        end
        
%         get the AST expression value for a variable name
        function AST = get(obj, varname)
            if(obj.map.isKey(varname))
                AST = obj.map(varname);
            else
                AST = [];
            end
        end
    end
    
end

