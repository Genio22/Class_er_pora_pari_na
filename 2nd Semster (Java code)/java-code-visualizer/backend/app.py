from flask import Flask, request, jsonify, send_from_directory
import subprocess
import os

app = Flask(__name__, static_url_path='', static_folder='../static')

def compile_and_run_java(code, input_data):
    with open("Main.java", "w") as file:
        file.write(code)
    
    compile_process = subprocess.run(["javac", "Main.java"], capture_output=True, text=True)
    if compile_process.returncode != 0:
        return compile_process.stderr
    
    run_process = subprocess.run(["java", "Main"], input=input_data, capture_output=True, text=True)
    if run_process.returncode != 0:
        return run_process.stderr
    
    return run_process.stdout

@app.route('/')
def serve_index():
    return send_from_directory(app.static_folder, 'index.html')

@app.route('/process_code', methods=['POST'])
def process_code():
    data = request.get_json()
    code = data['code']
    input_data = data.get('input', '')
    
    output = compile_and_run_java(code, input_data)
    
    return jsonify({'output': output})

if __name__ == '__main__':
    app.run(debug=True)