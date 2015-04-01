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
        
%         updates the map of variables with the actions in 'ast_list' 
%         (eg: x = x + 1) by using the previous basic blocks stored 
%         in 'BB_list'
        function update(obj, ast_list, BB_list)
            for i = 1:numel(ast_list)
                
                ast = ast_list{i};

    %           ast is an assignment
                if(isa(ast, 'Assignment'))
                    var_name = ast.left_node.name;
                    new_value_ast = copyAST(ast.right_node);

    %               find latest value of variables in new_value_ast
    %               do a Breadth First Search on the tree to find the 
    %               Variable nodes

    %               add root to queue
                    queue = { new_value_ast };

                    while(~isempty(queue))
                        node = queue{1}; queue = queue(2:end);

                        if(isa(node, 'Variable'))
    %                         lookup previous value of 'node' 
                            for j = numel(BB_list): -1 : 1
                                basic_block = BB_list{j};
                                old_var_ast = basic_block.get(var_name);

                                if(~isempty(old_var_ast))
    %                               found the previous value
    %                               make a copy of the ast
                                    copy_var_ast = copyAST(old_var_ast);

    %                               add to new_value_ast

    %                               no parent - this is the only node in 
    %                               new_value_ast
                                    if(isempty(node.parent_node))
                                        new_value_ast = copy_var_ast;
                                    elseif(node == node.parent_node.left_node)    
                                        node.parent_node.left_node = copy_var_ast;
                                        copy_var_ast.parent_node = node.parent_node;
                                    else
                                        node.parent_node.right_node = copy_var_ast;
                                        copy_var_ast.parent_node = node.parent_node;
                                    end

                                    break
                                end

                            end

                        elseif(~isa(node, 'Constant')) 
    %                       add children to queue
                            queue = [ queue,  ... 
                                     {node.left_node, ...
                                      node.right_node} ];
                        end
                    end

    %               update the basic block
                    obj.set(var_name, new_value_ast);
                end
            end
        end
        
    end
    
end

