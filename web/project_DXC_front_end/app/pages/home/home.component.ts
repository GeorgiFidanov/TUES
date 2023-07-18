import { Component, OnInit } from '@angular/core';

export type FeedbackForm = {
  name: string,
  surname: string,
  phone: string,
  clubs: string[],
  recommendScore: string,
  other: string[]
}
@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {

  checkboxTues = [
    { id: '1', value: false, name: 'I like programming' },
    { id: '2', value: false, name: 'Because of friends' },
    { id: '3', value: false, name: 'Because of my parents' },
    { id: '4', value: false, name: 'IT money' },
    { id: '5', value: false, name: 'Other:'}
  ]

  checkboxAnswers = [
    { id: '1', value: false, name: 'Robotics' },
    { id: '2', value: false, name: 'Cisco Academy' },
    { id: '3', value: false, name: 'Teenovator' },
    { id: '4', value: false, name: 'Literature club' },
    { id: '5', value: false, name: 'Movie club' },
    { id: '6', value: false, name: 'Teather club' }
  ]
  response: FeedbackForm = {
    name: '',
    surname: '',
    phone: '',
    clubs: [],
    recommendScore: '0',
    other: []
  }
  isNotSend = true;
  isOtherClicked = false;

  ngOnInit(): void {
  }

  onCheckboxChange(checkboxReturnValue: { id: string, value: boolean, name: string }): void {
    if (checkboxReturnValue.value) {
      this.response.clubs.push(checkboxReturnValue.name);
    } else {
      if (this.response.clubs.includes(checkboxReturnValue.name)) {
        const index = this.response.clubs.indexOf(checkboxReturnValue.name);
        if (index > -1) {
          this.response.clubs.splice(index, 1);
        }
      }
    }
  }

  onCheckboxOther(checkboxReturnValue: { id: string, value: boolean, name: string }): void {
    if (checkboxReturnValue.value) {
      if(checkboxReturnValue.name === 'Other:'){
        this.isOtherClicked = true;
      }
      this.response.other.push(checkboxReturnValue.name);
    } else {
      if(checkboxReturnValue.name === 'Other:'){
        this.isOtherClicked = false;
      }
      if (this.response.other.includes(checkboxReturnValue.name)) {       
        const index = this.response.other.indexOf(checkboxReturnValue.name);
        if (index > -1) {
          this.response.other.splice(index, 1);
        }
      }
    }
  }

  onClearResponse() {
    this.checkboxAnswers.forEach(answer => answer.value = false);
    this.checkboxTues.forEach(answer => answer.value = false);
    this.isOtherClicked = false;
    this.response = {
      name: '',
      surname: '',
      phone: '',
      clubs: [],
      recommendScore: '0',
      other: []
    }
  }

  onInputChange(field: string, event: Event) {
    const input = event.target as HTMLInputElement;
    if (field === 'name') {
      this.response.name = input.value;
    }

    if (field === 'surname') {
      this.response.surname = input.value;
    }

    if (field === 'phone') {
      this.response.phone = input.value;
    }
  }

  onInputRangeChange(value: string) {
    this.response.recommendScore = value;
  }

  onSend() {
    console.log(this.response)
    this.isNotSend = false;
  }

}
