import { Body, ClassSerializerInterceptor, Controller, Get, Param, Post, Render, Res, UseGuards, UseInterceptors } from "@nestjs/common";
import { ChatService } from "./chat.service";
import { User } from 'src/user/user.entity';
import { AuthGuard } from "src/auth/auth.guard";
import { Rooms } from "./rooms.entity";
import { createCipheriv, createDecipheriv, randomBytes, scrypt } from "crypto";
import { promisify } from "util";
import { RoomMessages } from "./roomsMessages.entity";
import { IsArray, IsNotEmpty, IsString } from "class-validator";


interface DataAdmins{
    value: string,
    label: string,
}

interface DataMembers{
    value: string,
    label: string,
}

interface DataLimited{
    value: string,
    label: string,
}

interface DataNotLimited{
    value: string,
    label: string,
}

export interface Data{
    admins: string[],
    members: string[],
}

// export interface Limited{
//     limited: string[],
   
// }

class ChatChronology {
    @IsString()
    username: string;

    @IsString()
    @IsNotEmpty()
    roomName: string;

    @IsString()
    @IsNotEmpty()
    type: string;
}

class AddMembersOptions {
    @IsString()
    @IsNotEmpty()
    channelName: string;

    @IsString()
    @IsNotEmpty()
    client: string;
}

class MuteBanOptions {
    @IsString()
    @IsNotEmpty()
    channelName: string;

    @IsString()
    @IsNotEmpty()
    mode: string
}

class MyState {
    @IsString()
    @IsNotEmpty()
    channelName: string;

    @IsString()
    @IsNotEmpty()
    client: string;
}

class AddAdmins {
    @IsString()
    @IsNotEmpty()
    nameChannel: string;

    @IsArray()
    @IsNotEmpty()
    newAdmins: string[];
}

class Members {
    @IsString()
    @IsNotEmpty()
    nameChannel: string;

    @IsArray()
    @IsNotEmpty()
    newMembers: string[];
}

class RemoveAdmins {
    @IsString()
    @IsNotEmpty()
    nameChannel: string;

    @IsString()
    @IsNotEmpty()
    admin: string;
}

class GroupChat {
    @IsString()
    @IsNotEmpty()
    builder: string;

    @IsString()
    @IsNotEmpty()
    nameGroup: string;

    @IsArray()
    @IsNotEmpty()
    members: string[];

    @IsString()
    @IsNotEmpty()
    password: string;
}

class ProtectedPass {
    @IsString()
    @IsNotEmpty()
    input: string;

    @IsString()
    @IsNotEmpty()
    channelName: string;
}

class GroupChat2 {
    @IsString()
    @IsNotEmpty()
    builder: string;

    @IsString()
    @IsNotEmpty()
    nameGroup: string;

    @IsArray()
    @IsNotEmpty()
    members: string[];

    @IsString()
    @IsNotEmpty()
    type: string;

    @IsString()
    @IsNotEmpty()
    password: string;
}

class DirectChat {
    @IsString()
    @IsNotEmpty()
    client: string;

    @IsString()
    @IsNotEmpty()
    userToChatWith: string;
}

@Controller("chat")
export class ChatController {
    constructor(private readonly chatService: ChatService,
    ) {}

    //Getters
    @Get('getuod')
    async UsersOnDB(): Promise<User[]>{
        return (await this.chatService.getUsersOnDB());
    }

    @Get('getall')
    async getAllChannels() {
        return (await this.chatService.getAllChannels());
    }

    @Get('getpublic')
    async getPublicChannels(): Promise<Rooms[]> {
        return (await this.chatService.getPublicChannels());
    }

    @Get('private')
    async getPrivateChannels() {
        return (await this.chatService.getPrivateChannels());
    }
    
    @Get('getprotected')
    async getProtectedChannels() {
        return (await this.chatService.getProtectedChannels());
    }
    
    @Get('getChannel/:channelName')
    async getChannel(@Param('channelName') channelName: string){
        return (await this.chatService.getChannel(channelName));
    }

    @Get('allmembers/:roomName')
    async GetAllChatMembers(@Param('roomName') roomName: string): Promise<User[]>{
        const members = await this.chatService.getChatMembers(roomName);
        return (members);
    }

    @Get('allmembersandstatus/:roomName')
    async GetAllChatMembersAndStatu(@Param('roomName') roomName: string): Promise<User[]>{
        const members = await this.chatService.getChatMembersAndStatus(roomName);
        return (members);
    }

    @Get('members/:roomName')
    async GetChatMembers(@Param('roomName') roomName: string): Promise<User[]>{
        const admins = await this.chatService.getRoomAdmins(roomName);
        const members = await this.chatService.getChatMembers(roomName);
        const owner = await this.chatService.getRoomOwner(roomName);
        await Promise.all(await admins.map(async (element) => {
            const index = members.findIndex(x => x.username === element.username);
            if (index != -1)
                members.splice(index, 1);
        }))
        const index2 = await members.findIndex(x => x.username == owner.username);
        if (index2 != -1)
            members.splice(index2, 1);
        return (members);
    }

    @Get('admins/:roomName')
    async GetRoomAdmins(@Param('roomName') roomName: string): Promise<User[]>{
        const owner = await this.chatService.getRoomOwner(roomName);
        const admins = await this.chatService.getRoomAdmins(roomName);
        const index = admins.findIndex(x => x.username === owner.username);
        if (index != -1)
            admins.splice(index, 1); // Da levare per includere owner negli admin.. se serve
        return (admins);
    }

    @UseGuards(AuthGuard)
    @UseInterceptors(ClassSerializerInterceptor)
    @Post('chrono')
    async GetChatChronology(@Body('user') username: string, @Body('roomName') roomName: string, @Body('type') type: string){
        const messages = await this.chatService.getMessages(roomName, type);
        return (messages);
    }
    
    @Get('clientrooms/:client_id')
    async GetClientRooms(@Param('client_id') client_id: number){
        return await this.chatService.getClientRooms(client_id);
    }
    
    @Get('membership/:client_id')
    async GetMemberships(@Param('client_id') client_id: number){
        const groups = await this.chatService.getMemberships(client_id);
        return groups;
    }

    @Get('getmembership/:client_id')
    async GetMemberships2(@Param('client_id') client_id: number){
        const groups = await this.chatService.getMemberships(client_id);
        return groups;
    }

    @Get('getFriendsChatList/:client')
    async GetFriendsChatList(@Param('client') client: string){
        return await this.chatService.getDirectChannels(client);
        //return await this.chatService.getFriendsRooms(client);
    }

    @Post('addMembersOptions')
    // @UsePipes(ValidationPipe)
    async GetAddMembersOptions(@Body('channelName') channelName: string, @Body('client') client: string){
        const options = await this.chatService.getAddMembersOptions(channelName, client);
        return options;
    }

    //work in progress

    @Get('getNotBannedUsers/:channelName')
    async GetNotBannedUsers(@Param('channelName') channelName: string) {
        const usersToSplice = await this.GetChatMembers(channelName);
        const banned = await this.GetBannedUsers(channelName);
        await Promise.all(await banned.map(async (element) => {
            const index = usersToSplice.findIndex(x => x.username === element)
            if (index != -1)
                usersToSplice.splice(index, 1);
        }))
        return (usersToSplice.map(a => a.username));
    }

    @Get('getBannedUsers/:channelName')
    async GetBannedUsers(@Param('channelName') channelName: string) {
        return this.chatService.getBannedUsers(channelName);        
    }

    @Get('getNotMutedUsers/:channelName')
    async GetNotMutedUsers(@Param('channelName') channelName: string) {
        const usersToSplice = await this.GetChatMembers(channelName);
        const muted = await this.GetMutedUsers(channelName);
        await Promise.all(await muted.map(async (element) => {
            const index = usersToSplice.findIndex(x => x.username === element)
            if (index != -1)
                usersToSplice.splice(index, 1);
        }))
        return (usersToSplice.map(a => a.username));
    }

    @Get('getMutedUsers/:channelName')
    async GetMutedUsers(@Param('channelName') channelName: string) {
        return this.chatService.getMutedUsers(channelName);        
    }

    @Post('getMuteBanOptions')
    async GetMuteBanOptions(@Body('channelName') channelName: string, @Body('mode') mode: string) {
        return this.chatService.getMuteBanOptions(channelName, mode);
    }

    @Post('getMyState')
    async GetMyState(@Body('channelName') channelName: string, @Body('client') client: string){
        return this.chatService.getMyState(channelName, client);
    }

    @Get('getMyMutesAndBans/:client')
    async GetMyMutesAndBans(@Param('client') client: string){
        return this.chatService.getMyMutesAndBans(client);
    }
    //end work in progress

    //Adders
    @Post('addAdmins') //da testare
    async addAdmins(@Body('nameChannel') nameChannel: string, @Body('newAdmins') newAdmins: string[]) {
        return (await this.chatService.addAdmins(nameChannel, newAdmins));
    }

    @Post('addMembers')
    async addMembers(@Body('nameChannel') nameChannel: string, @Body('newMembers') newMembers: string[]){
        return (await this.chatService.addMembers(nameChannel, newMembers));
    }

    //Removers
    @Post('removeAdmins')
    async removeAdmins(@Body('nameChannel') nameChannel: string, @Body('admin') admin: string){
        return (await this.chatService.removeAdmin(nameChannel, admin));
    }

    //Generaters
    @Post('createGroupChat')
    async CreateGroupChat(@Body('builder') builder: string,
    @Body('nameGroup') nameGroup: string,
    @Body('members') members: string[],
    @Body('pwd') password: string){
        const room = await this.chatService.createGroupChat(builder, nameGroup, members, password);
        return room;
    }

    @Post('checkProtectedPass')
    async CheckProtectedPass(@Body('input') input: string, @Body('channelName') channelName: string){
        return await this.chatService.checkProtectedPassword(input, channelName);
    }

    @Post('createGroupChat2')
    async CreateGroupChat2(@Body('builder') builder: string,
    @Body('nameGroup') nameGroup: string,
    @Body('members') members: string[],
    @Body('type') type: string,
    @Body('password') password: string){
        const room = await this.chatService.createGroupChat2(builder, nameGroup, members, type, password);
        return room;
    }

    @Post('createDirectChat')
    async CreateDirectChat(@Body('client') client: string,
        @Body('userToChatWith') userToChatWith: string){
            return await this.chatService.createDirectChat(client, userToChatWith);
        }

    //fatto con socket emit... non dovrebbe servire
    // @Get('expiredMuteOrBan/:channelName')
    // async ExpiredMuteOrBan(@Param('channelName') channelName: string){
    //     await this.chatService.expiredMuteOrBan(channelName);
    // }

    //Setters
    @Post('editChannel')
    async EditChannel(
        @Body('channelName') channelName: string,
        @Body('type') type: string,
        @Body('adminsSetted') adminsSetted: string[],
        @Body('password') password?: string,
        @Body('newName') newName?: string ){
            await this.chatService.editChannel(channelName, type, adminsSetted, password, newName); //impostare un return?
    }

    @Post('editUsers')
    async editUsersOnChannel(@Body('data') data: string[], @Body('channelName') channelName: string){
        this.chatService.editUsersOnChannel(data, channelName);
    }

    @Post('setJoin')
    async setJoin(
        @Body('client') client: string,
        @Body('channelName') channelName: string,
        @Body('joined') joined: boolean){
            await this.chatService.setJoin(client, channelName, joined);
    }

    @Post('handleMuteBan')
    async HandleMuteBan(
        @Body('channelName') channelName: string,
        @Body('limited') limited: string[],
        @Body('mode') mode: string,
        @Body('time') time: number,
        @Body('reason') reason: string,
    ){
        if (mode === 'kick')
            return await this.chatService.kickUsers(limited, channelName);
        const room = await this.chatService.getRoomByName(channelName);
        let currentLimited = (mode === 'ban') ? room.bannedUsers : room.mutedUsers;
        let oppositeLimited = (mode === 'ban') ? room.mutedUsers : room.bannedUsers;
        currentLimited = currentLimited ? currentLimited : [];
        oppositeLimited = oppositeLimited ? oppositeLimited : [];
        const cleanLimited: string [] = [];
        const rowsToUpdate: string [] = [];
        const rowsToDelete: string [] = [];
        const rowsToAdd: string [] = [];
        await Promise.all(await limited.map(async (element) => {
            cleanLimited.push(element);
        }))

        await Promise.all(await cleanLimited.map(async (element) => {
            const index = oppositeLimited.findIndex(x => x === element);
            if (index > -1)
            {
                rowsToUpdate.push(element);
                oppositeLimited.splice(index, 1);
            }
        }))
        await Promise.all(await cleanLimited.map(async (element) => {
            if (rowsToUpdate.findIndex(x => x === element) === -1)
            {            
                if (currentLimited.findIndex(x => x === element) === -1)
                    rowsToAdd.push(element);
            }
        }))

        await Promise.all(await currentLimited.map(async (element) => {           
            if (cleanLimited.findIndex(x => x === element) === -1)
                rowsToDelete.push(element);
        }))


        // Leonardo era qui
        function aggiungiSecondi(secondi: number, date: Date) {
            date = new Date(date.setMilliseconds(secondi * 1000))    
        }
        var expDate = new Date();
        aggiungiSecondi(time, expDate);
        await this.chatService.updateMuteBanTable(channelName, rowsToDelete, rowsToUpdate, rowsToAdd, mode, reason, expDate);
        await this.chatService.handleMuteBan(room, mode, cleanLimited, oppositeLimited);
    }

    //Checkers

    @Get('checkTarget/:client')
    async CheckTarget(@Param('client') client: string){
        const user = await this.chatService.checkTarget(client);
        if (user)
            return true;
        else
            return false;
    }

    @Get('checkChannelName/:channelName')
    async CheckChannelName(@Param('channelName') channelName: string) {
        return {'ret': await this.chatService.checkChannelName(channelName)}
    }

    @Post('checkJoined')
    async checkJoined(@Body('client') client: string, @Body('channelName') channelName: string){
        return await this.chatService.checkJoined(client, channelName);
    }

    //path per test
    @Get('test/:nameChannel')
    async test(@Param('nameChannel') nameChannel: string){
        return await this.chatService.test(nameChannel);
    }

    @Get('updateChannelUsersList')
    async UpdateChannelUsersList(){
        await this.chatService.updateChannelUsersList();
    }
}