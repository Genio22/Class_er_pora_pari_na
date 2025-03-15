document.addEventListener('DOMContentLoaded', function() {
    var editor = CodeMirror.fromTextArea(document.getElementById('javaCode'), {
        lineNumbers: true,
        mode: "text/x-java",
        theme: "default"
    });

    document.getElementById('codeForm').addEventListener('submit', function(event) {
        event.preventDefault();
        const code = editor.getValue();

        // Make a request to the server to process the code
        fetch('/process_code', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ code: code })
        })
        .then(response => response.json())
        .then(data => {
            // Display the result
            const resultDiv = document.getElementById('result');
            if (data.image) {
                resultDiv.innerHTML = `<img src="data:image/png;base64,${data.image}" alt="AST Visualization">`;
            } else {
                resultDiv.textContent = 'Error processing code';
            }
        })
        .catch(error => {
            console.error('Error:', error);
        });
    });
});