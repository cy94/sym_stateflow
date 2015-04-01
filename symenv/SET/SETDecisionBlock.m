classdef SETDecisionBlock < handle
    %SETDECISIONBLOCK Stores the path constraint during symbolic execution
    %   Stores a single AST (boolean) node for the transition guard
    %   during symbolic execution
    
    properties
        ast
    end
    
    methods
        function set(obj, ast)
            obj.ast = ast;
        end
        
        function ast = get(obj)
            ast = obj.ast;
        end
        
%         creates a new path constraint with the condition in 'ast'
%         (eg: x < 10) by using all previous basic blocks stored 
%         in 'BB_list'
        function update(obj, ast, BB_list)
            new_ast = copyAST(ast);
            
%           find latest value of variables in new_ast
%           do a Breadth First Search on the tree to find the
%           Variable nodes
            
%           add root to queue
            queue = { new_ast };
            
            while(~isempty(queue))
                node = queue{1}; queue = queue(2:end);
                
                if(isa(node, 'Variable'))
%                   lookup previous value of 'node'
                    node_var_name = node.name;

                    for j = numel(BB_list): -1 : 1
                        basic_block = BB_list{j};
                        old_var_ast = basic_block.get(node_var_name);
                        
                        if(~isempty(old_var_ast))
%                           found the previous value
%                           make a copy of the ast
                            copy_var_ast = copyAST(old_var_ast);
%                           add to new_value_ast
                            
%                           no parent - this is the only node in
%                           new_ast
                            if(isempty(node.parent_node))
                                new_ast = copy_var_ast;
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
            new_ast
            obj.set(new_ast);
        end
    end
    
end

