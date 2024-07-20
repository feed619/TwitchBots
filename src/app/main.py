from flask import Flask
from router import router_get_data_to_sent  # Импортируйте Blueprint из routes.py

app = Flask(__name__)

app.register_blueprint(router_get_data_to_sent)

if __name__ == "__main__":
    app.run(debug=True)
