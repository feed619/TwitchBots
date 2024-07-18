# routes.py
from flask import Blueprint, request, jsonify
from source.channel_id import get_channel_id
from source.send_message import send_message

router_get_data_to_sent = Blueprint('router_get_data_to_sent', __name__)


@router_get_data_to_sent.route('/api/sent_data', methods=['POST'])
def send_data():
    data = request.get_json()  # Получите данные из запроса
    response = {
        'status': 'success',
        'data_received': data
    }
    send_message(data.get("accounts"), data.get("channel_id"),
                 data.get("paste"), data.get("sleep"))
    print("Готово")
    return jsonify(response)


@router_get_data_to_sent.route('/api/get_data', methods=['GET'])
def get_data_2():
    data = {"message": "Hello from Python backend!"}
    return jsonify(data)


@router_get_data_to_sent.route('/api/get_id', methods=['GET'])
def send_id():
    channel_name = request.args.get('channel_name')
    print(channel_name)
    channel_id = get_channel_id(channel_name)
    return jsonify({"message": channel_id})
