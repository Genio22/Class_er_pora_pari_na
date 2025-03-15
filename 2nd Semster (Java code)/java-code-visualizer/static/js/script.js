document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('codeForm').addEventListener('submit', function(event) {
        event.preventDefault();
        const code = document.getElementById('javaCode').value;
        const input = document.getElementById('userInput').value;

        // Make a request to the server to compile and run the code
        fetch('/process_code', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ code: code, input: input })
        })
        .then(response => response.json())
        .then(data => {
            // Display the compiler output
            const outputDiv = document.getElementById('output');
            outputDiv.textContent = data.output;
        })
        .catch(error => {
            console.error('Error:', error);
            const outputDiv = document.getElementById('output');
            outputDiv.textContent = 'Error processing code';
        });
    });
});