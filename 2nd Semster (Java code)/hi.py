import javalang
import graphviz

def parse_java_code(code):
    tree = javalang.parse.parse(code)
    return tree

def visualize_ast(tree):
    dot = graphviz.Digraph(comment='Java AST')
    
    def add_nodes(node, parent_id=None):
        node_id = str(id(node))
        label = type(node).__name__
        
        if hasattr(node, 'name'):
            label += f' ({node.name})'
        
        dot.node(node_id, label)
        
        if parent_id:
            dot.edge(parent_id, node_id)
        
        if isinstance(node, javalang.ast.Node):
            children = node.children
            if callable(children):
                children = children()
            for child in children:
                if isinstance(child, javalang.ast.Node):
                    add_nodes(child, node_id)
                elif isinstance(child, list):
                    for grandchild in child:
                        if isinstance(grandchild, javalang.ast.Node):
                            add_nodes(grandchild, node_id)
    
    add_nodes(tree)
    return dot

if __name__ == '__main__':
    java_code = '''
    public class Example {
        public static void main(String[] args) {
            System.out.println("Hello, world!");
        }
    }
    '''
    
    tree = parse_java_code(java_code)
    dot = visualize_ast(tree)
    dot.render('ast', format='png', cleanup=True)