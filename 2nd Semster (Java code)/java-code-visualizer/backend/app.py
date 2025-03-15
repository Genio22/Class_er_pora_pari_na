from flask import Flask, request, jsonify, send_from_directory
import javalang
import graphviz
import base64
from io import BytesIO

app = Flask(__name__, static_url_path='', static_folder='../static')

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

@app.route('/')
def serve_index():
    return send_from_directory(app.static_folder, 'index.html')

@app.route('/process_code', methods=['POST'])
def process_code():
    data = request.get_json()
    code = data['code']
    
    tree = parse_java_code(code)
    dot = visualize_ast(tree)
    img = dot.pipe(format='png')
    img_base64 = base64.b64encode(img).decode('utf-8')
    
    return jsonify({'image': img_base64})

if __name__ == '__main__':
    app.run(debug=True)