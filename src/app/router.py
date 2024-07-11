# routes.py
from flask import Blueprint, request, jsonify

router_get_data_to_sent = Blueprint('router_get_data_to_sent', __name__)


@router_get_data_to_sent.route('/api/sent_data', methods=['POST'])
def get_date():
    data = request.get_json()  # Получите данные из запроса
    response = {
        'status': 'success',
        'data_received': data
    }
    print(data)
    return jsonify(response)


@router_get_data_to_sent.route('/api/get_data', methods=['GET'])
def get_data_2():
    data = {"message": "Hello from Python backend!"}
    return jsonify(data)
